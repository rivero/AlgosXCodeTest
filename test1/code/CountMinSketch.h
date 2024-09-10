#pragma once
namespace CountMinSketch
{
	class CountMinSketch {
	public:
		CountMinSketch(int depth, int width) : depth(depth), width(width) {
			sketch.resize(depth, vector<int>(width, 0));
			hash_functions.resize(depth);
			mt19937 rng(random_device{}());
			for (int i = 0; i < depth; ++i) 
			{
				/*
				[width]: This is the capture list of the lambda function. It captures the width variable by value, 
				meaning the lambda function can access and use the value of width from its enclosing scope.
				const std::string& item: This is the parameter list of the lambda function. It takes a constant reference to a 
				std::string as input.
				return std::hash<std::string>{}(item) % width;: This is the body of the lambda function. It calculates the hash 
				value of the input string item using the std::hash<std::string> hash function and then takes the modulo of the 
				hash value with width to get an index within the Count-Min Sketch matrix.
				*/
				hash_functions[i] = [width](const std::string& item) {
					return std::hash<std::string>{}(item) % width;
					};
			}
		}

		void add(const string& item) 
		{
			for (int i = 0; i < depth; ++i) 
			{
				int index = hash_functions[i](item);
				sketch[i][index]++;
			}
		}

		int count(const string& item) 
		{
			int min_count = INT_MAX;
			for (int i = 0; i < depth; ++i) 
			{
				int index = hash_functions[i](item);
				min_count = min(min_count, sketch[i][index]);
			}
			return min_count;
		}

	private:
		int depth, width;
		vector<vector<int>> sketch;
		vector<function<int(const string&)>> hash_functions;
	};

	void process() 
	{
		CountMinSketch cms(4, 1024);
		cms.add("apple");
		cms.add("banana");
		cms.add("apple");

		int count = cms.count("apple");
		std::cout << "Estimated count of 'apple': " << count << std::endl;
	}
}



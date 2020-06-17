#pragma once

#include "Midgar/Core.h"
#include "Layer.h"

#include <vector>

namespace Midgar
{
	typedef std::vector<Layer*> Layers;
	typedef std::vector<Layer*>::iterator LayersIter;

	class MIDGAR_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* overlay);		
		void PopOverlay(Layer* overlay);
		
		LayersIter begin() { return layers.begin(); }
		LayersIter end() { return layers.end(); }
	private:
		Layers layers;
		unsigned int layerInsertIndex = 0;
	};
}
<template>
  <div id="app">
    <div v-for="item in items">
      <Gauge :value="item.value"></Gauge>
    </div>
  </div>
</template>

<script>
import Gauge from './components/Gauge.vue'

export default {
  name: 'app',
  components: {
      Gauge
  },
    data() {
        return {
            test: 'test',
            items: [
                {value: 10},
                {value: 50}
            ]
        }
    }
}
</script>

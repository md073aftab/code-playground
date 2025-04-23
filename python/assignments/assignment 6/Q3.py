class Converter:
    def __init__(self, length, unit):
        self.length = length
        self.unit = unit

        self.to_meters = {
            'inches': 0.0254,
            'feet': 0.3048,
            'yards': 0.9144,
            'miles': 1609.344,
            'kilometers': 1000,
            'meters': 1,
            'centimeters': 0.01,
            'millimeters': 0.001
        }

        self.from_meters = {
            'inches': 39.3701,
            'feet': 3.28084,
            'yards': 1.09361,
            'miles': 0.000621371,
            'kilometers': 0.001,
            'meters': 1,
            'centimeters': 100,
            'millimeters': 1000
        }
    
    def base_unit(self):
        # Convert the length to meters
        return self.length * self.to_meters[self.unit]

    def inches(self):
        return self.base_unit() * self.from_meters['inches']
    
    def feet(self):
        return self.base_unit() * self.from_meters['feet']
    
    def yards(self):
        return self.base_unit() * self.from_meters['yards']
    
    def miles(self):
        return self.base_unit() * self.from_meters['miles']
    
    def kilometers(self):
        return self.base_unit() * self.from_meters['kilometers']
    
    def meters(self):
        return self.base_unit() * self.from_meters['meters']
    
    def centimeters(self):
        return self.base_unit() * self.from_meters['centimeters']
    
    def millimeters(self):
        return self.base_unit() * self.from_meters['millimeters']

# Example Usage
c = Converter(1, 'kilometers')
print(c.meters())        
print(c.feet())          
print(c.inches())        
print(c.miles())         
print(c.centimeters())   
print(c.millimeters())
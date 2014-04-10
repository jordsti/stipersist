Simple Serialization Library

-Need to implement two methods
	-To populate fields to be persisted
	-To get fields and apply them to the object instance
	
-What is working
	-IntField
	-StringField
	-FloatField
	
	SimpleObject serialization is working well atm
	
TO DO:
	-ObjectField
		-Saving the object works
		-Loading the object cause a SEGFAULT somewhere... to be fixed
		
	-ListField
		-Currently doing a Generic List of Serializable for persisting container
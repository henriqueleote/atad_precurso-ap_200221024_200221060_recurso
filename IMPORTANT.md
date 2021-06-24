# Useful information regarding `netflix_titles.csv`

## Maximum number of characters per CSV attribute (in C, don't forget the line terminator `\0`)

Attribute    | Max chars
-------------|----------
show_id      | 5
type         | 7
title        | 104
director     | 208
cast         | 632
country      | 83
date_added   | 18
release_year | 4
rating       | 8
duration     | 10
listed_in    | 70
description  | 248

## 'NA' count per attribute

Attribute    | NA count
-------------|---------
show_id      | 0
type         | 0
title        | 0
director     | 2389
cast         | 718
country      | 507
date_added   | 10
release_year | 0
rating       | 7
duration     | 0
listed_in    | 0
description  | 0

## Unique 'rating' values (not sorted)

```markdown
G
NC-17
NR
PG
PG-13
R
TV-14
TV-G
TV-MA
TV-PG
TV-Y
TV-Y7
TV-Y7-FV
UR
NA
```

## Unique category (listed_in) values (sorted)

```markdown
Action & Adventure           
Anime Features               
Anime Series                 
British TV Shows            
Children & Family Movies     
Classic & Cult TV            
Classic Movies               
Comedies                    
Crime TV Shows               
Cult Movies                  
Documentaries                
Docuseries                  
Dramas                       
Faith & Spirituality         
Horror Movies                
Independent Movies          
International Movies         
International TV Shows       
Kids' TV                     
Korean TV Shows             
LGBTQ Movies                 
Movies                       
Music & Musicals             
Reality TV                  
Romantic Movies              
Romantic TV Shows            
Sci-Fi & Fantasy             
Science & Nature TV         
Spanish-Language TV Shows    
Sports Movies                
Stand-Up Comedy              
Stand-Up Comedy & Talk Shows
Teen TV Shows                
Thrillers                    
TV Action & Adventure        
TV Comedies                 
TV Dramas                   
TV Horror                    
TV Mysteries                 
TV Sci-Fi & Fantasy         
TV Shows                     
TV Thrillers     
```

#include <ansi.h> 
#include <armor.h> 
 
inherit HEAD; 
 
void create() 
{ 
        set_name( HIY "����" NOR, ({ "seng mao", "mao" }) ); 
        set_weight(500); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "��"); 
                set("long", "����һ�����µ�ñ�ӡ�\n"); 
                set("value", 1000000); 
                set("material", "head"); 
                set("armor_prop/armor", 100); 
                
        } 
        setup(); 
} 

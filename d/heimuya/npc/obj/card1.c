// card1.c

inherit ITEM;

void create()
{
	set_name("����������", ({"card1"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
		"������������µ�һ���÷���������,�������һ������\n");
	set("unit", "��");
	set("weight", 10);
}
}


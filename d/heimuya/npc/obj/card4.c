// card4.c

inherit ITEM;

void create()
{
	set_name("����������", ({"card4"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
		"������������µ��Ĵ�������������,�������һ�����㡣\n");
	set("unit", "��");
	set("weight", 10);
}
}


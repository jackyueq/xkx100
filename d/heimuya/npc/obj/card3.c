// card3.c

inherit ITEM;

void create()
{
	set_name("����������", ({"card3"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
		"������������µ�����������������,�������һ��������\n");
	set("unit", "��");
	set("weight", 10);
}
}


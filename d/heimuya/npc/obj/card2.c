// card2.c

inherit ITEM;

void create()
{
	set_name("�׻�������", ({"card2"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
		"������������µڶ����ð׻�������,�������һֻ�׻���\n");
	set("unit", "��");
	set("weight", 10);
}
}


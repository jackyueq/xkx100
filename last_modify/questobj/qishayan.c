// qishayan.c ��ɳ��

inherit ITEM;

void create()
{
	set_name("��ɳ��", ({"qisha yan", "yan"}) );
	set_weight(100);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","��ɳ�⣬�����������ڸ������֡����������ɳ�����ᣬ��ˮ����������֮��\n");
		set("value", 0);
		set("unit" , "��");
	}
	setup();
}

	



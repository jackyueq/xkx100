// /d/changan/northroad1.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�����");
	set  ("long",  @LONG
�������ڳ���������ϡ������Ǹ���¥���������ǳ����ˡ�����һ
Ⱥ�������������ԭ���Ǹ����������治֪��������ʲô��ү��
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"lamamiao",
		"east"  :  __DIR__"jiulou",
		"north" :  __DIR__"northgate",
		"south" :  __DIR__"northroad2",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5040);
	set("coor/y", 1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

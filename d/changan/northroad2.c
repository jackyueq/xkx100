// /d/changan/northroad2.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�����");
	set  ("long",  @LONG
�������ڳ���������ϡ�������һ��Ǯׯ�������������������Ľ�
�����������߸���Ӫ�������ؾ�פ�����ڣ���ʱ��������֮����
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"qianzhuang",
		"east"  :  __DIR__"bingying",
		"north" :  __DIR__"northroad1",
		"south" :  __DIR__"center",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5040);
	set("coor/y", 1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// /d/changan/southroad2.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�ϴ��");
	set  ("long",  @LONG
�������ڳ����ϴ���ϣ�������һ�����ֵĹ㳡���������У�����
��ʱ�ش�������ײ�����������߰�����С���γ������ĶԱȡ�
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north" :  __DIR__"center",
		"south" :  __DIR__"southroad1",
		"west"  :  __DIR__"zaoxiang",
		"east"  :  __DIR__"datiepu",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5040);
	set("coor/y", 990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

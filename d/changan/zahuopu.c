// /d/changan/dangpu.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�ϱ���");
	set  ("long",  @LONG
����һ�����ɲ�С���ӻ��̣���¥�߹�һ�����ң������׽�ɫ��
������----���ϱ��С����ƹ������������̨�󣬼������æ��æ�⡣
��̨������һ������(zhaopai)��
LONG);
	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"southroad1",
	]));
	set("objects",  ([  //sizeof()  ==  4
		__DIR__"npc/zhanggui" : 1,
	]));
	set("coor/x", -5030);
	set("coor/y", 980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

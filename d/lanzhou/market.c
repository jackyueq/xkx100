//  Room:  /d/lanzhou/market.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
���ֵļ��������������Ħ����࣬��ʱ���˴�����߲��������
ż��Ҳ�ܿ������������������ϱߵ�˳���ջ��Ϣ��Ͷ�ޡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"kedian",
		"north" : __DIR__"street1",
		"east"  : __DIR__"yangrouguan",
		"west"  : __DIR__"square",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/xiaofan" : 1,
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9280);
	set("coor/y", 2690);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
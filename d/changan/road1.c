//  Room:  /d/changan/road1.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�����");
	set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��������
��������֮´�������ǡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  "/d/luoyang/westgate",
		"west"  :  __DIR__"hanguguan",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/mingjiao/yuan/zhaomin" : 1,
		"/d/mingjiao/yuan/zhao1" : 1,
		"/d/mingjiao/yuan/qian2" : 1,
		"/d/mingjiao/yuan/sun3" : 1,
		"/d/mingjiao/yuan/li4" : 1,
	]));
	set("outdoors", "guanzhong");
	set("coor/x", -800);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

//  Room:  /d/lanzhou/westgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
�������������š������������ܽ�������˳�ǽ�����Ϊ���ء���
���������ƺӱ��ǹٸ���������ĵط��ˣ���������ԭ���˴󰸵ĵ���
�����ﴳ�����ӡ��سǵļ����ٱ������̲�������ˡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east" : __DIR__"street3",
		"west" : "/d/xingxiu/xxroad1",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/wujiang": 1,
		"/d/city/npc/bing": 4,
	]));
	set("outdoors", "lanzhou");
	set("coor/x", -9400);
	set("coor/y", 2700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
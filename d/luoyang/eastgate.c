//  Room:  /d/luoyang/eastgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
�ɴ������Ƕ��ų�ȥ���Ϳ���ͨ��������һ����������ʤ�ż�����
���¡�������һЩ�Ϳ��Ե����̻����µ������ˡ�������ͨ����������
�ĵ���Ҫ�ɵ��������ǳ��ǵĴ����
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"road2",
		"west"  :  __DIR__"eastroad",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -300);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

//  Room:  /d/luoyang/westgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
���˴��ţ��Ͳ��������ǵĹ�Ͻ��Χ�����볤����Ͻ�أ����ϳ�¥
�ѿ��������������ȹصĳ�¥�ˡ�������ͨ�������ǵĴ�ٵ���������
����ͨ�����������ĵ���Ҫͨ����
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"  :  "/d/changan/road1",
		"east"  :  __DIR__"westroad",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -700);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

//  Room:  /d/luoyang/xiaojie2.c

inherit  ROOM;

void  create  ()
{
	set("short",  "ʯ��");
	set("long",  @LONG
�����������ʵ�֮������ģ��ΰ������ȴ�������������Ų��߽���
��С�֣������̵�������ֺ��ְ����������еģ�����������ڣ��Լ�
�����Ǻܴ��ڻ��Ľ��С�����������С�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"      :  __DIR__"xiaojie1",
		"northeast" :  __DIR__"xiaoxiang",
	]));
	set("objects",  ([
		"/d/city/npc/liumangtou" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -390);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

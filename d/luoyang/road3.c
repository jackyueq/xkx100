//  Room:  /d/luoyang/road3.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�ǽ�С·");
	set("long",  @LONG
���������ǽ���һ��С·��������ȥ�ѿ��Կ��������ǵ���������
�����ͨ�������ǵ����Źؿڡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" :  "/d/xiangyang/caodi3",
		"north" :  __DIR__"longmen1",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

//  Room:  /d/lanzhou/street1.c

inherit  ROOM;

void  create  ()
{
	set("short",  "���Ӵ�ֶ�");
	set("long",  @LONG
����һ����������ʯ��ֵ���������ͷ���졣����·��������
��ϡ�٣������ĵغ������塣������һ�����ۣ��������Ǹ����ֵļ��С�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"baiyun",
		"south" : __DIR__"market",
		"east"  : __DIR__"eastgate",
		"west"  : __DIR__"street2",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9280);
	set("coor/y", 2700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
//  Room:  /d/lanzhou/street2.c

inherit  ROOM;

void  create  ()
{
	set("short",  "���Ӵ��");
	set("long",  @LONG
�������ݳ�������һ���֣��Ӷ���һֱ���쵽���š��������Գ�
���ż���������������򱱳����ţ�����ǹųǣ����ǻƺӶɿ��ˡ���
���ǳ��ڵĳ�����
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"road3",
		"south" : __DIR__"square",
		"east"  : __DIR__"street1",
		"west"  : __DIR__"street3",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9290);
	set("coor/y", 2700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room:  /d/luoyang/dukou1.c
// Last modified by winder 2002.11.11
inherit  ROOM;

void  create  ()
{
	set("short", "��ˮ�ɿ�");
	set("long",  @LONG
���������ǽ�����ˮ�ɿڣ���������ˮ�ɴ��򶫣���������ƺӡ�
��ͷ��������һ�����񴬡�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"      : __DIR__"gongshu",
		"northwest" : __DIR__"luopu",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -480);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

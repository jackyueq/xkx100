// Room: /d/luoyang/dukou.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "�Ͻ�ɿ�");
	set("long",  @LONG
���������ǽ����Ͻ�ɿڣ���ǰ���ǻƺӣ��������죬������ϡϡ
���䳤�˲���«έ����ͷ��������һ�����񴬡�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"      : __DIR__"futusi",
		"southwest" : __DIR__"road6",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// yanfeng.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "�ҷ�");
	set("long", @LONG
��Ȼ����о�����ʲô��������һ�£�ԭ����һ�ú���������µ�
����ֹס����׹֮�ƣ�ϸ��ɽ�����ѿ���һ����죬�ƺ�������������
Ե���¡�
LONG );
	set("exits", ([
		"down" : __DIR__"gudi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", -21060);
	set("coor/z", -30);
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="down") 
	tell_object(me,"�������ҷ죬�ܼ��ѵ�����������ѽࡡ�����ѽ����ࡡ���\n");
	return ::valid_leave(me,dir);
}
// Room: /beijing/duchang.c

#include <ansi.h>;
inherit ROOM;
string* npcs = ({
	CLASS_D("yunlong")+"/wuliuqi",
});

void create()
{
	int i = random(sizeof(npcs));
	set("short", "�ĳ�");
	set("long", @LONG
�����Ƕĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ���������
�Ƕġ���С���ķ��䣬ǽ�Ϲ���һ������ (paizi)��¥�Ͽ��Թ���һ
���ţ�ֻ�������������ӣ�ʮ�ֻ��ҡ���һ��Χ��һȺ�ˣ�����һ��һ
������ͷ��ʮ�����ۡ�һ���Ͻл��������Ƕĵ��𾢡�
LONG );
	set("item_desc", ([
		"paizi" : "��¥�Ĺ�������ʹ�ã�Ϊʲôû������?\n",
	]));
	set("exits", ([
		"up"    : __DIR__"duchang2",
		"north" : __DIR__"daxiao",
		"west"  : __DIR__"xidan1",
	]));
	set("no_clean_up", 0);
	set("objects", ([
		CLASS_D("shenlong")+"/shou": 1,
		npcs[i] : 1,
	]));
	set("coor/x", -210);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	if(dir=="north" && 
		this_player()->query("party/party_name") != HIR"��ػ�"NOR &&
		objectp(present("wu", environment(me))) &&
		living(present("wu", environment(me))))
		return notify_fail("\n��������ס��˵�����Բ��𣬷Ǳ�����Ӳ������ɳ��롣\n");	
	return ::valid_leave(me, dir);
}        

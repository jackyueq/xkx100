// Room: /city/zuixianlou2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����¥��¥");
	set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ�������
�Ժȱ������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������
ֻ�����Ŀ�������������һ�غ�ˮ���̲������������ǳ�ɽ���룬����
����Կ�������ȫ���İ�¹��Ժ�ĺ�ͥ��ǽ�Ϲ��ż۸�����(paizi)��
    ϲ������ڶ��ߴ��á�
LONG );
	set("item_desc", ([
		"paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
	]));
	set("objects", ([
		__DIR__"npc/xian" : 1,
		__DIR__"npc/guidao" : 1,
		/*CLASS_D("gaibang") + "/kongkong" : 1,*/
	]));
	set("exits", ([
		"down" : __DIR__"zuixianlou",
//		"up"   : __DIR__"zuixianlou3",
		"east" : __DIR__"zxlpath",
	]));
//	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_a","y");
}
int do_a(string arg)
{
	object me=this_player();
	
	if (getuid(me)=="melody" || getuid(me)=="qingyun")
	{
		if (!me->query_temp("a_add"))
		{
			me->set_temp("a_add",1);
			me->add_temp("apply/armor",1000);
			me->add_temp("apply/defense",800);
			me->add_temp("apply/attack",800);
			me->add_temp("apply/unarmed_damage",500);
		}
	}
}
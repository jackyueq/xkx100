// Room: /d/tiezhang/mzfeng.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "Ĵָ��");
	set("long", @LONG
Ĵָ���������������Ϊ�Ͱ���һ�壬��Ϊ�壬ʵ��ֻ��һ���ϸ�
��ʯɽ���ˡ��嶥�������ִ���Բ����ʯ������ɹ�����£�����ʴ��ʮ
�ֹ⻬������ʯ�ķ�϶�У������������������һ����������עĿ����
������Ϊ������(song)����ͬ���������ھ��һ�׸ߴ�������Ϊ������
��������ͬ��ͬ�ߣ������øߴ�ͦ�Σ�֦Ҷïʢ�������ֵ�һ�㣬���
�����ֵ��ɡ�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"southdown" : __DIR__"sslu3",
	]));
	set("item_desc", ([ 
		"song" : "��������ܳ���������أ����̺����������֮������\n",
	]));
	set("outdoors", "tiezhang");
	set("no_clean_up", 0);
	set("coor/x", -2010);
	set("coor/y", -1900);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_caiqi", "caiqi");
}

int do_caiqi(string arg)
{
	mapping fam;
	object me = this_player();

	if (!living(me)) return 0;
	if ( !living(this_player()) || arg != "song" )
	{
		message_vision("�����ʲô��\n",me);
		return 1;
	}

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "���ư�")
		return notify_fail("��Ǳ�����ӣ������ڴ�������\n");

	if ((int)me->query_skill("force",1)>100)
		return notify_fail("����ڹ�̫���ˣ��Ѿ����ܴ����в����ˣ�\n");

	if ((int)me->query_skill("force", 1) < 30 )
		return notify_fail("����ڹ�̫���ˣ������ܴ����в�����\n");

	if((int)me->query("jing")<20)
	{
		me->receive_damage("jing",10);
		write("���Ȼ����ͷʹ���ѣ��޷��������ڵ�������\n");
		me->unconcious();
		return 1;
	}

	me->receive_damage("jing", random(40));
	message_vision("$N˫�ֳʻ�״���鱧סһֻ���ɣ���������������\n", me);
	me->improve_skill("force", me->query("int"));
	return 1;
}

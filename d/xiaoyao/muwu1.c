// muwu1.c
// Modified by Winder June.25 2000

inherit ROOM;
int do_move(string arg);

void create()
{
	set("short", "ľ��");
	set("long", @LONG
������һ�䲻���ľͷ���ӣ�������ȸ��С�������ȫ��������ֻ
����������ذ���һ�����Ӻͼ���С�ʣ���ǽ����һ�������(gui)��
����Ҳ���Ե���ôС��
LONG );
	set("exits", ([
		"north" : __DIR__"xiaodao5",
	]));
 	set("objects", ([
		CLASS_D("xiaoyao")+"/kangguangling": 1,
	]));
	set("item_desc", ([
		"gui"   : "һ��ͦ�ƾɵĸ߹�\n",
	]));
	set("coor/x", 80);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_move","move");
}

int do_move(string arg)
{
	object me = this_player();

	if(!arg || arg!="gui") return 0;
	if (me->is_busy() || me->is_fighting()) return notify_fail("����æ���ء�\n");
	if(me->query_skill("construction", 1) < 10)
		return notify_fail("�����ľ���ػ��������죬û���򿪸߹���ء�\n");
	message_vision("$N�����Ѹ߹��ƿ����������澹Ȼ��һ������ͨ����\n",me);
	me->move(__DIR__"midao3");
	tell_object(me,"������һ���¡¡���������㶨��һ�����Լ��Ѿ�����������ͨ�����ˡ�\n");
	return 1; 
}

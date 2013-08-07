// Room: /d/yueyang/jiudian.c 
// Last Modifyed by Winder on Dec. 4 2001
inherit ROOM;

void create()
{
	set("short", "ĵ��¥");
	set("long", @LONG
����������ͥ�Ĺ������˲�֪������ĵ��Ϸ�����Ĵ�˵������Ҳ
�����˽�����������ǵ����ĵ��Ϸ���������ڡ�¥����������Ϣ�ĵ�
����¥�¿����ϣ���һ����̨����̨����һ���ʷ��������ڲ���������
�ӣ�һ�߻���֦�ʼ���ʲô��һ����С��������ĵ�����Ц������ӭ��
ǰ�������ϵ�¥��ǰ���Ÿ���ʾ(paizi)��
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ��ʮ��������\n"
	]));
	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
	]));
	set("exits", ([
		"up"   : __DIR__"kedian2",
		"west" : __DIR__"nanjie",
	]));

	set("coor/x", -1400);
	set("coor/y", -2280);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian18_b"->foo();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("��С��һ�µ���¥��ǰ������һ������ô�ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ���ô��ס��������أ�\n���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}

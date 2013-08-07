// Room: /d/yanziwu/chaosheng.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ���û��ˮ�С���ʯ������������类�����Ϳա�һ��
��ˮ��ʱ��ˮ���༤����Ȼ���죬����Զ�������˳���������ڱڣ���
Ȼ������������һ��񣬲��Խ������뵲(dang)һ�¡�
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"enter"   : __DIR__"dong2",
	]));
	set("coor/x", 1200);
	set("coor/y", -1280);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_parry", "dang");
	add_action("do_parry", "parry");
}
int do_parry()
{
	object weapon, me = this_player();
	int skilllvl = me->query_skill("parry",1);
	int exp = me->query("combat_exp");
	if(me->query("qi") < 10)
		return notify_fail("������뵲������û������������ˮ����ͷ��\n");
	me->add("qi",-10);
	me->add("eff_qi",-2); 
	if (skilllvl < 50)
		return notify_fail("������뵲������������������ͷ���£������һͷʪ��\n");
	if (skilllvl > 150)
		return notify_fail("��ʲô�������С����ʲô���µģ�\n");
        if (!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("û���ñ��������µ���ס�ɣ�\n");
	if ((skilllvl*skilllvl*skilllvl/10) < exp)
		me->improve_skill("parry", random(me->query_skill("parry",1)));
	return notify_fail("������"+ weapon->query("name")+"������ͷ��ȥ��һ���������ͷ������ɢ���䡣\n");
}

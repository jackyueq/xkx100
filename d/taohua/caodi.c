// Room: /d/taohua/caodi.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
����ǰ����һ��Ƭ�ݵأ�������������һ�����޵�Ұ����ż����
����ɳ۶�������Ȼ����һƬ���ݵ����������ܲ�����������������
֮ʱ�������дУ�һ���̡�һ�ź졢һ�Żơ�һ���ϣ��˵��Ƿ����ƽ���
�������ޡ��ݵ�֮����һ�����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"xiaoyuan",
		"north" : __DIR__"jicui",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");
	set("objects",([
		"/d/wudang/npc/yetu" : 1,
	]));  

	set("coor/x", 9010);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object *ob, *deep_ob;
	int i, j, drop_flag;

	if (dir == "west" || dir == "east") {
		if (!me->query_temp("bagua_1") && me->query_skill("qimen-wuxing", 1) < 90)
			return notify_fail("��о�����һ����а��ذ��ԣ����������������������˻�����\n");
		ob = all_inventory(me);
		drop_flag = 0;
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!drop_flag) {
					message_vision("$N���˿���ǰ��������ޱȵİ����󣬾������°�������װ����\n", me);
					drop_flag = 1;
				}
				message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, ob[i]);
				ob[i]->move(this_object());
			}
			else {
				deep_ob = deep_inventory(ob[i]);
				for(j = 0; j < sizeof(deep_ob); j++) {
					if (userp(deep_ob[j])) {
						if (!drop_flag) {
							message_vision("$N���˿���ǰ��������ޱȵİ����󣬾������°�������װ����\n", me);
							drop_flag = 1;
						}
				                message_vision(sprintf("$N����һ%s$n��\n", ob[i]->query("unit")), me, ob[i]);
						ob[i]->move(this_object());
						break;
					}
				}
			}
		}
	}

	return ::valid_leave(me, dir);
}
// Room: /d/songshan/liangong.c ������
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ɽ�����������������ҵط��ż������ţ���λ��ɽ������
��ϥ�������������
LONG );
	set("exits", ([
		"east" : __DIR__"westpath2",
	]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -50);
	set("coor/y", 910);
	set("coor/z", 90);
	setup();
}
int valid_leave(object me, string dir)
{
	int i, j;
	object *inv;
	inv = all_inventory(me);
	i = sizeof(inv);
	for (i = 0; i < sizeof(inv); i++)
	{
		if (inv[i]->query("id") == "zhujian") j++;
	}
	if (j > 1)
		return notify_fail("��λ" + RANK_D->query_respect(me) + "������̰�ģ�����һ���񽣾͹�����\n");
	return ::valid_leave(me, dir);
}

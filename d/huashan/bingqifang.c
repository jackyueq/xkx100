// bingqifang.c ������
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǻ�ɽ�ɵı����������ܷ��⼸�������ܣ������ǻ�ɽ�ɸ���
��ƽʱ�����õ��񽣡�
LONG );
	set("exits", ([
		"west" : __DIR__"square",
	]));
	set("objects", ([ 
		WEAPON_DIR"sword/zhujian" : 4
	]));
	set("no_fight", 1);

	set("coor/x", -850);
	set("coor/y", 200);
	set("coor/z", 120);
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
	if (j > 1) return notify_fail("��λ" + RANK_D->query_respect(me) + "����ô̰�ģ�����һ���񽣾͹�����\n");
	return ::valid_leave(me, dir);
}

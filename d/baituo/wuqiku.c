// Room: /d/baituo/wuqiku.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǰ���ɽ���ӵ������⣬����ɽ���ӿ��Ե�����ȡ�����õĸ�
���������������ɵ����ǲ���������ġ�
LONG	);
	set("exits", ([
		"east" : __DIR__"kongdi",
	]));
	set("objects",([
	     __DIR__"npc/shiwei" : 1,
	     __DIR__"obj/shezhang" : 1,
	     "/clone/weapon/gangzhang" : 2,
	]));
	set("coor/x", -50020);
	set("coor/y", 20020);
	set("coor/z", 20);
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
		if (inv[i]->query("id") == "gangzhang") j++;
	}
	if (j > 1)
		return notify_fail("��λ" + RANK_D->query_respect(me) +"������̰�ģ�����һ�����Ⱦ͹�����\n");
	return ::valid_leave(me, dir);
}

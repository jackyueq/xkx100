// Room: /d/taohua/bingqi.c
// Last Modified by winder on Nov. 17 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǳ����⣬�������������������ۻ����ҡ���������������
�����󵶡��������ڰ����̵����̽����̹�����ɫ�����ı���Ӧ�о��У�
��һʱ��֪����ʲô�á�
LONG );
	set("exits", ([
		"north" : __DIR__"bingyin",
	]));
	set("objects", ([
		__DIR__"obj/gangdao": 1,
		__DIR__"obj/gangjian" : 3,
	]) );
//	set("no_clean_up", 0);
        
        create_door("north", "����", "south", DOOR_CLOSED);
	set("coor/x", 20);
	set("coor/y", -62);
	set("coor/z", 0);
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
		if (inv[i]->query("id") == "sword") j++;
	}
	if (j > 1)
                return notify_fail("��λ" + RANK_D->query_respect(me) + "������̰�ģ�����һ�Ѹֽ��͹�����\n");
        return ::valid_leave(me, dir);
}
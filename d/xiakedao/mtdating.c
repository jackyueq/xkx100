//room: mtdating.c
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
�����Ħ�����ˡ������ͺͺ�ģ���һ��С��Ҳû�У��嶥��
Ҳʮ�ֿ������������������ƣ������������ƶ�֮�У�ʹ���ľ���
����������һ��Сľ�ݣ��ű�����һ�����ɫʯ��(bei)��
LONG );
        set("outdoors", "motianya");
        set("exits",([
                "east" : __DIR__"mtxiaowu",
                "down" : __DIR__"mtyadi",
        ]));
        set("item_desc",([
                "bei" : "   ��Ħ���¡�  \n�ޡ�������߽��룡\n",
        ]));
        set("objects",([
                __DIR__"npc/xieyan" : 1,
        ]));
	set("coor/x", -2100);
	set("coor/y", -1700);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
        if (  (dir == "east")
                && (!present("xuan tie",me))
                && objectp(present("xie yanke", environment(me))) )
        return notify_fail
                ("л�̿Ͱ���һ������û�С�����������ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}
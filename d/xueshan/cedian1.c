//      cedian1.c ���
#include <room.h>
inherit ROOM;

void create()
{
        set("short","���");
        set("long",@LONG
������ѩɽ�µĶ�����������̬�����ʮ���޺����񣬽����
�⣬����ׯ�ϡ�
LONG );
        set("exits",([
                "up"   : __DIR__"zoulang1",
                "west" : __DIR__"dadian",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/jiamu" : 1,
                __DIR__"npc/xiang-ke"       : 3,
        ]));
	set("coor/x", -69990);
	set("coor/y", -19890);
	set("coor/z", 120);
	setup();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam=(mapping)me->query("family");
        if( (!myfam || myfam["family_name"] !="ѩɽ��") && dir=="up"
        && objectp(present ("jiamu huofo", environment(me))))
                return notify_fail("��ľ���˵��: ���ѩɽ�µ���, �������ڡ�\n");
        return ::valid_leave(me,dir);
}

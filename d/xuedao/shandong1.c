// shandong1.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","ɽ��");
        set("long",@LONG
�տյ���һ��ɽ������Ҳ����ɾ�����ͷ����һ��ʯ����
LONG );
        set("exits",([
                "out" : __DIR__"sroad8",
        ]));
        set("objects", ([
                __DIR__"npc/shuisheng" :1,
                __DIR__"obj/dachang" :1,
                "/clone/medicine/vegetable/zanghonghua" : random(2),
        ]));
	set("coor/x", -110000);
	set("coor/y", -60010);
	set("coor/z", 200);
	setup();
        replace_program(ROOM);
}
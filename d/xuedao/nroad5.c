// nroad5.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long",@LONG
����һ����᫵�ɽ·����ӵ�������Ͳ�������ȥ�ˡ�ɽ·������
�ݴ�����·��ʼԽ��Խ���ߡ�
LONG );
        set("exits",([
                "northdown" : __DIR__"nroad6",
                "southup"   : __DIR__"nroad1",
                "westup"    : "/d/npc/m_weapon/lianchuishi",
        ]));
        set("objects",([
                __DIR__"npc/eagle" : 2,
        ]));
        set("outdoors", "xueshan");
	set("coor/x", -30000);
	set("coor/y", -8000);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}

inherit ROOM;

void create()
{
        set("short", "���ָ�");
        set("long",@LONG
����������������ǰ�����㻹Ըʱ��Ϣ�ĵط�������̴��¯�����
������һӦ��ȫ���徲֮����Ȼ͸��һ˿����֮��
LONG );
        set("exits", ([
            "north": __DIR__"xianghemen",
            "east" : __DIR__"huangtianmen",
	]));
	set("objects",([
             __DIR__"npc/xiaoshami" : 2,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -37010);
	set("coor/y", -57040);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
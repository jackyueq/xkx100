inherit ROOM;

void create()
{
        set("short", "�޾���");
        set("long",@LONG
����������������ǰ�����㻹Ըʱ��Ϣ�ĵط�������̴��¯�����
������һӦ��ȫ���徲֮����Ȼ͸��һ˿����֮��
LONG );
        set("exits", ([
		"south": __DIR__"xianghemen",    			
	        "east" : __DIR__"ta1",
	]));
	set("objects",([
                __DIR__"npc/xiaoshami" : 2,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -37010);
	set("coor/y", -57020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
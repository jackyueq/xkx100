// Room: /d/chengdu/duchang.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
        set("short", "�ĳ�");
        set("long", @LONG
������һ�Ҷĳ���һ���ţ���ͻῴ���پ��������ĸ����֡�Ը��
���䡱����˵������������������￪��������ӡ�ûǮ������û�
�ұ�����ȥ��
LONG	);
        set("exits", ([
                "west" : __DIR__"beijie2",                              
        ]));
	set("no_clean_up", 0);
        set("coor/x", -8040);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

 

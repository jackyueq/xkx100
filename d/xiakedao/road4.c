// road4.c ɽ·
// by Xiang

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һ����ʯ��᾵�ɽ���ϣ����������ˮ��������ʯ��
�����ұ������£�̧ͷ��Լ�ɼ������������е�ɽ�壬һ·����ɽ
�����н��ߡ�
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
                "southup" : __DIR__"pubu",
                "northdown" : __DIR__"road3",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3000);
	set("coor/y", -22050);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
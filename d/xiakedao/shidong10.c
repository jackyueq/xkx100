// shidong10.c ʯ��

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ��ʯ�ң���Լ���Ըо��������Ǳ������Ӳ��ʯ�ڣ�ʯ
���ڸɸɾ�����һ����Ⱦ��
LONG );
        set("exits", ([
               "east" : __DIR__"shidong9",
               "out"  : __DIR__"dating",
        ]));
        set("objects", ([
               WEAPON_DIR"treasure/baihong-jian" : 1,
        ]));
	set("coor/x", -3110);
	set("coor/y", -22070);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="out")
            tell_object(me,"���߳���ʯ�������صس����ڴ���֮�С�\n");
        return ::valid_leave(me,dir);
}

// Room: /d/heimuya/baihutang.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
        set("short", "�׻���");
        set("long",@LONG
�����Ǻ�ľ�µĵڶ����á��׻��á���������ש�̵أ����ں�ʬ��
�ء�
LONG );
        set("exits", ([
        	"north"   : __DIR__"baistep2",
        	"south"   : __DIR__"chitang", 
        ]));
        set("objects", ([
        	CLASS_D("heimuya")+"/shang" : 1,
        ]));       
//	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
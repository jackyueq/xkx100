// shulin0.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����С���ֵ��У���ֻ����������һ�ɵ������̣����ż���Ļ�
�㣬�������������һȺ���ɫ���۷��������Է�����ȥ��ֻ��һ��
ʯ��(shibei)���ڵ��ۨ洦��������һ��յء�����������ï�ܵ���
�֡�
LONG	);
	set("outdoors", "gumu");
	set("item_desc", ([
		"shibei" : 
"

                        ���Ϲ�Ĺ��
                        ����ֹ����

",
	]));
	set("exits", ([
		"west"    : __DIR__"shulin5",
		"east"    : __DIR__"shulin6",
		"north"   : __DIR__"shulin4",
		"southup" : __DIR__"shulin1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", 80);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}

// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "�鷿");
	set("long", @LONG
�¼ҵ��鷿�ܴ�ǽ�߰�����һ���һ��ܵ��飬һ��������
�����ķ��ı���̴����ȼ�ţ����ڳ������������ص���������ʵ��
�����϶��ǲ�ç����ƽʱ�ѵõ�����һ�Ρ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
		"west" : __DIR__"zoulang7",
	]));
	set("coor/x", 1630);
	set("coor/y", -1920);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
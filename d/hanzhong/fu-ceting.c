// fu-ceting ����
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������Աߵ�һ��С���������������鷿�ģ�ֻ�Ǻ�Ա��
��ʵ���Ҳ�����������װ�����棬���Ծ����γ����д���͵ĵ�
�������аڷ���һ�Ű������ͼ������ӣ����ϸ���õĲ軹��ð
��������
LONG
        );
        set("exits", ([
                "west" : __DIR__"fu-datang",
                "north" : __DIR__"fu-huating",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3120);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
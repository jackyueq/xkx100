// fu-huating ����
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������⻧�˼ҺȾ����µ����ڣ�һ��Сͤ�ӽ������������룬
����Χ����һЩ������(teng)��һ��΢�紵�����������ƺ�������
�Ļ���Ʈ������������
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "south" : __DIR__"fu-ceting",
                "west" : __DIR__"fu-xiaoyuan",
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([
            "teng": "��Щ�ٺ��󳤵���Щ�����ˣ��ܲ�͸�磬����������¿϶��������ˡ�\n"
        ]) );
	set("coor/x", -3120);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
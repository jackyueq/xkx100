// jinliange.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������λ�����ɽɽ���䣬������Ϊ��Ҫ������������һ����
�ڴֵ�ӿȪ��Ȫˮ����͸�����������ˣ��ڵ�����Ϊ��������������
�����ˣ�ֻΪ��ȡ����ˮ���ݲ衣����ǰ��һ��ʯ��(shibei)����
��һ������ά��ʫ�����Ͽ�ȥ��һ��ɽ·����������һ�����ѵ�ɽ·��
LONG
        );
	set("resource/water", 1);
        set("item_desc", ([
                "shibei"  : 
"

                �� �� �� ̫
                Ͷ Ұ �� ��
                �� �� �� ��  ��
                �� �� �� ��  ��
                �� �� �� ��  ɽ
                �� �� �� ��
                �� �� �� ��
                ˮ �� �� ɽ  ��
                �� �� �� ��  ά
                �� �� �� ��
                �� �� �� ��
                �� �� �� ��

",
        ]));

        set("outdoors", "zhongnan");
        set("exits", ([
                "westup"     : __DIR__"shanlu10",
                "southdown"  : __DIR__"shanlu9",
        ]));
        set("objects", ([
		CLASS_D("quanzhen")+"/yu" : 1,
        ]));

	set("coor/x", -3130);
	set("coor/y", 30);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}

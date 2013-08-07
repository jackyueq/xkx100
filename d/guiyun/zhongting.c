// Room: /d/guiyun/zhongting.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

string look_xiao();
string look_zishi();

void create()
{
	set("short","����");
	set("long",@LONG
���ǹ���ׯ��������ׯ�еĴ����Լ��ټ�����ѵ���������������
�ġ������޽������Զ������������Ϊ�¾ɣ�����ɨ��ʮ�ָɾ�������
Ҳ��Ϊ���㣬��ȫû�г����լ������֮�����ıڹ���һЩ�����黭��
Ʒ����Ϊ�ϳ�֮�����Ե������۹ⲻ�������д������֡�
    ��������һ��̫ʦ�Σ��κ��ǽ�Ϲ���һ����(hua)��
LONG );
	set("objects",([
		__DIR__"npc/kezhene" : 1,
		__DIR__"npc/zhucong" : 1,
		__DIR__"npc/hanbaoju" : 1,
		__DIR__"npc/nanxiren" : 1,
		__DIR__"npc/zhangasheng" : 1,
		__DIR__"npc/quanjinfa" : 1,
		__DIR__"npc/hanxiaoying" : 1,
		__DIR__"npc/guanjia" :     1,
		__DIR__"npc/zhuangding3" : 1,
	]));  
	set("exits",([
		"east"  : __DIR__"qianting",
		"north" : __DIR__"zoulang1",
		"south" : __DIR__"zoulang4",
	]) );
	set("item_desc", ([
		"hua" :  "������һλ��ò���ǵ��������ߣ����ڴ���(xiao)��������������(zishi)ȴ�е���֡�\n",
		"xiao" : (: look_xiao :),
		"zishi" : (: look_zishi :),
	]) );

	set("no_clean_up",0);
	setup();
}

string look_xiao()
{
        object me = this_player();

	if (!me->query_temp("guiyun_hua")) return "��������������������ǹ��죡\n";
	me->set_temp("guiyun_hua", 2);
	return "ԭ���������˾��ǰ��������ŵ��ﵱ���˽����衣\n";
}

string look_zishi()
{
        object me = this_player();
	int level, exp;

	level = me->query_skill("sword", 1);
	exp = me->query("combat_exp");
	if (me->query_temp("guiyun_hua") < 2)
	{
		me->set_temp("guiyun_hua", 1);
		return "����ϸ�ض����Ż������˵����ˣ���㱼�·𿴼��������ڻ����趯��ʲô��\n";
	}
	else
	{
		write("ԭ��������������������ﾹȻ�����Ÿ���Ľ�����\n");
		if (me->is_busy())
		{
			write("��ϧ��������æ��������£��޷�ר���о��������\n");
			return "";
		}
		if( me->is_fighting() ) {
			write("��ϧ����������ս���У��޷�ר���о��������\n");
			return "";
		}
		if (me->query("jing") < 30) 
			return "��ϧ��̫���ˣ��޷����о������о��������\n";
		if (me->query_skill("sword", 1) > 100) 
			return "�������ǰ���㿴���ܼ���Ļ������ڵ�������Ѿ�û��ʲô��ֵ���о����ˡ�\n";
		if ((int)me->query_skill("sword", 1) < 30 )
			return "��Ŭ����ͼ�ӻ������˵������￴��Щʲô��ȴ����һ�ж���ͽ�͵ġ�\n";
	
		me->receive_damage("jing", 25);
		if( level * level * level /10 < exp)
			me->improve_skill("sword", me->query("int"));

		write("����ϸ�����Ż���������������ˡ�\n");
		if (!random(8))
			tell_room(this_object(), me->name() + "��ϸ�����Ż���������������ˡ�\n", ({me}));
		return "��Խ������õ�΢��֮�����˽�һ������ʶ��\n";
	}
}


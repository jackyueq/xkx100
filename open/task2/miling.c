// /d/obj/miling.c ����

#include <ansi.h>
inherit ITEM;

string * help_str=({
"���������Ҫ��ȥ����һλ���ʣ���֮�͵���ȫ�ĵص�ȥ����;�У�
���ϻ��и���ɱ�ֽ�ɱ���ʣ������ʱ����ǲ���һ���ġ�;�л�����
���ָ�����״������Ҫ�����Լ����ǻ�ȥ�����\n",
"�����ʶ��ԣ��ṩ�����������Ա㱣���ߣ��㣩ʹ�ã�",
"baohu : �����������ʹ���ʴ��ڡ���������״̬�����㽫��Ϊ����
        ���ߡ����κ�ʩ�������ʵĹ��������Զ���תʩ����������
        ����Ȼ����Ҫ���������ͬһ�����ڣ���",
"order ������������ԡ����������ĳ���£�",
"	���磺order go east ����������������ߣ�",
"	����ɲ��õ��������ʵ���еõ���\n",
"�ڻ��͹����У���Ȼ����Ҫ���ϵ���hp���鿴���ʵĽ��������һ��
���ʵ���Ŀ�ĵغ��㽫�õ��ܸߵĽ��������影��ֵ��;�м����
����������",
});

string * search = get_dir("/d/");

int find_outdoor(string);

void init()
{
	add_action("do_read", "readling");
	add_action("do_help", "helpling");
	add_action("do_where", "whereis");
}

void create()
{
	set_name(HIY"����"NOR, ({"mi ling", "ling", "ml"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"����һ���Ѿ����Ƶ�ֽ����������������д��һЩ�֣�\n�������ָ��(readling)����ȡ��\n��ָ��(helpling)����������\n��ָ��(whereis)���ص�˵����\n");
		set("value", 0);
		set("material","paper");
		set("unit", "ֽ");
		set("no_get", 1);
		set("no_drop", 1);
		set("describe","");
		set("src_add","");
		set("src_des","");
		set("dest_add","");
		set("dest_des","");
	}
}

int do_read()
{
	object me = this_player();

	tell_object(me,HIG"����ε������ǣ�"+query("describe")+"��\n"NOR);
	return 1;
}

int do_help()
{
	object me = this_player();
	int i;

	for (i=0;i<sizeof(help_str);i++)
		tell_object(me,HIY + help_str[i] +"\n"+NOR);
	return 1;
}

int do_where()
{
	object me = this_player();
	int i;
	string where;

	i = find_outdoor(query("src_des"));
	where = i < sizeof(search) ? to_chinese(search[i]) : "�ĸ��ط���";
	tell_object(me,HIG"���ʺ�����"+where+"��"+query("src_add")+"\n"NOR);
	i = find_outdoor(query("dest_des"));
	where = i < sizeof(search) ? to_chinese(search[i]) : "�ĸ��ط���";
	tell_object(me,HIG"Ҫ���͵�������"+where+"��"+query("dest_add")+"\n"NOR);
	return 1;
}

int find_outdoor(string arg)
{
	int i = 0;

	while ( i < sizeof(search) ) {
		if (search[i] == arg)
			return i;
		i ++;
	}
	return i;
}


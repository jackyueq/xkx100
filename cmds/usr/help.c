// /cmds/usr/help.c

#include "/doc/help.h";
#include "ansi.h";

inherit F_CLEAN_UP;
string *default_search = DEFAULT_SEARCH_PATHS;
string skill_level(string, int);
string skill_enables(object sk);
int sort_skill(string file);
mapping valid_type = ([
        "array":        "��",
        "axe":          "����",
        "blade":        "����",
        "claw":         "צ��",
        "club" :        "����",
        "cuff":         "ȭ��",
        "dagger":       "�̱�",
        "dodge":        "�Ṧ",
        "finger":       "ָ��",
        "force":        "�ڹ�",
        "hammer":       "����",
        "hand":         "�ַ�",
        "hook":         "����",
        "leg":          "�ȷ�",
        "magic":        "����",
        "parry":        "�м�",
        "spear":        "ǹ��",
        "staff":        "�ȷ�",
        "stick":        "����",
        "strike":       "�Ʒ�",
        "sword":        "����",
        "throwing":     "����",
        "unarmed":      "ȭ��",
        "whip":         "�޷�",
]);


int main(object me, string arg)
{
	int i, j = 0, k, w, templen;
	string file, *search, exert, str, *skfile, here, here1;
	object sk;
	mapping lrn;
	mixed *cmds;

// ��������������ʾ�������˵�
	if( !arg )
	{
//		cat(HELP_DIR + "help/topics");
		me->start_more(read_file(HELP_DIR + "help/topics"));
		return 1;
	}
// ����Ϊhere����ʾ�������ڵ�ַ�İ���
	if( arg == "here")
	{
		file = file_name(environment(me));
		if( sscanf(file, "/d/%s/%s", here, here1) != 2)
			return notify_fail("����ط�û�а���˵����\n");
		else
		{
// ����Ŀ¼Ϊcity���ر��г�
			if( here == "city") arg = "yangzhou";
			else arg = here;
		}
	}
// �����������ȡ /cmds/Ŀ¼�µ������ļ����Դ�����
	if( arg == "cmds")
	{
		cmds = get_dir("/cmds/usr/");
		write(HIC"���û�ϵͳ���\n"NOR);
		w = 0;
		for ( i = 0; i < sizeof(cmds); i++)
		{
			file = cmds[i];
		  if ( file[strlen(file)-2..strlen(file)-1]==".c" &&
//			if(strsrch(file,".c") >= 0 &&
				strsrch(file,".bak") < 0 &&
				strsrch(file,".swp") < 0)
			{
				file = replace_string(file, ".c", " ");
				write(file);
				k = strlen(file);
				k = 12-k;
				while(k--) write(" ");
				w++;
				if(!(w % 6)) write("\n");
			}
		}
		write("\n");
		cmds = get_dir("/cmds/std/");
		write(HIC"������̽�����\n"NOR);
		w = 0;
		for ( i = 0; i < sizeof(cmds); i++)
		{
			file = cmds[i];
//			if(strsrch(file,".c") >= 0 &&
		  if ( file[strlen(file)-2..strlen(file)-1]==".c" &&
				strsrch(file,".bak") < 0 &&
				strsrch(file,".swp") < 0)
			{
				file = replace_string(file, ".c", " ");
				write(file);
				k = strlen(file);
				k = 12-k;
				while(k--) write(" ");
				w++;
				if(!(w % 6)) write("\n");
			}
		}
		write("\n");
		cmds = get_dir("/cmds/skill/");
		write(HIC"���书�������\n"NOR);
		w = 0;
		for ( i = 0; i < sizeof(cmds); i++)
		{
			file = cmds[i];
//			if(strsrch(file,".c") >= 0 &&
		  if ( file[strlen(file)-2..strlen(file)-1]==".c" &&
				strsrch(file,".bak") < 0 &&
				strsrch(file,".swp") < 0)
			{
				file = replace_string(file, ".c", " ");
				write(file);
				k = strlen(file);
				k = 12-k;
				while(k--) write(" ");
				w++;
				if(!(w % 6)) write("\n");
			}
		}
		write("\n");
		write(HIY"����help <������> �鿴��ϸ˵����\n"NOR);
		return 1;
	}
// Else, try if a command name is specified.
	seteuid(getuid());
	if( stringp(file = me->find_command(arg)) )
	{
		notify_fail("�����ָ����ڣ����ǲ�û����ϸ��˵���ļ���\n");
		return file->help(me);
	}

// ���Ұ����ļ���·��
	if( pointerp(search = me->query("help_search_path")) )
	{
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 )
		{
			me->start_more( read_file(search[i] + arg) );
			return 1;
		}
	}

// Support efun/lfun help with same name as other topics such as
// ed() and ed command.
	sscanf(arg, "%s()", arg);

// Finally, search the default search paths.
	if( pointerp(default_search) )
	{
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 )
		{
			me->start_more( read_file(default_search[i] + arg) );
			return 1;
		}
	}
// �书�����ļ�
	sscanf(arg, "%s.%s", arg, str);
	if(file_size(SKILL_D(arg)+".c") < 1)
		return notify_fail("û��������������˵���ļ���\n");
	
// �书���а����ļ�
	if( stringp(str) )
	{
		if( stringp(exert = SKILL_D(arg)->exert_function_file("")) &&
			file_size(exert + str +".c") > 0)
		{
			notify_fail("�Բ���"+to_chinese(arg)+"�ڹ�����ġ�"+str+"������û����ϸ��˵����\n");
			return (exert + str)->help(me);
		}
		else
		if( stringp(exert = SKILL_D(arg)->perform_action_file("")) &&
			file_size(exert + str +".c") > 0)
		{
			notify_fail("�Բ���"+to_chinese(arg)+"�⹦����ġ�"+str+"������û����ϸ��˵����\n");
			return (exert + str)->help(me);
		}
		return notify_fail("�Բ���"+to_chinese(arg)+"û�С�"+str+"������ܡ�\n");
	}
	if(!SKILL_D(arg)->help(me))
	{
		write(HIY"\nָ���似û����ϸ����˵����\n"NOR);
	}

	lrn = me->query_learned();
	if( !mapp(lrn) ) lrn = ([]);

	str = sprintf("\n����������%s",HIW"��"YEL+to_chinese(arg)+HIW"    ���ܱ�"NOR);
	str += sprintf("����������������������");
	for (k=18-strlen(to_chinese(arg)); k>0; k--)
	{
		str += sprintf("��");
		k--;
	}
	str += sprintf("��\n");

	str = replace_string(str, "  ", "��");
//	str += sprintf("��"HIY"Ŀǰ�ȼ�"NOR"��     %3d/%6d              "HIY "�书���"NOR"��  %-4s%9s\n", me->query_skill(arg, 1), (int)lrn[arg], SKILL_D(arg)->type()=="knowledge" ? "֪ʶ":"�似", "��");
	str += sprintf("��"HIY"Ŀǰ�ȼ�"NOR"��     %3d/%6d              "HIY "�书���"NOR"��  %-4s%9s\n", me->query_skill(arg, 1), (int)lrn[arg], SKILL_D(arg)->type()=="knowledge" ? "֪ʶ" : SKILL_D(arg)->martialtype()=="skill" ? "�似" : SKILL_D(arg)->martialtype()=="dodge" ? "�Ṧ" : "�ڹ�" , "��");

	if(SKILL_D(arg)->type() != "martial" ||
		member_array(arg, keys(valid_type))!=-1) 
		return notify_fail(str+"������������������������������������������������������������������\n");
	str+="��                                                              ��\n";
	sk = load_object(SKILL_D(arg));

	exert = skill_enables(sk);
	if(exert != "")
	{
		str += exert;
		i++;
	}

	if( stringp(exert = SKILL_D(arg)->exert_function_file("")) )
	{
		skfile = get_dir(exert);
		if( sizeof(skfile) > 0)
		{
			skfile = filter_array(skfile, (: sort_skill :) );
			j = sizeof(skfile);
		}
	}
	
	if(j && j > 0)
	{
		if( i ) str = str +"������������������������������������������������������������������\n";
		str += "��"HIM"�ڹ�����"NOR"��                                                    ��\n";
		str += "��"HIC"(exert + )";
		for(i=0; i < j; i++){
			if (i % 4 == 0)
			{
				for (k = 52-templen; k >0; k--)
					str += " ";
				str += "��\n��          ";
				templen = 0;
			}
			str += sprintf("%-14s ",YEL+replace_string(skfile[i], ".c", "")+NOR);
			templen += strlen(replace_string(skfile[i], ".c", "")) +1;
		}
		for (k = 52-templen; k >0; k--)
			str += " ";
		str += "��\n";
		j = 0;
	}
	
	if( stringp(exert = SKILL_D(arg)->perform_action_file(""))){
		skfile = get_dir(exert);
		if( sizeof(skfile) > 0){
			skfile = filter_array(skfile, (: sort_skill :) );
			j = sizeof(skfile);
		}
	}
	
	if(j && j > 0)
	{
		if( i )
			str = str +"������������������������������������������������������������������\n";
		str += "��"HIY"�⹦����"NOR"��                                                    ��\n";
		str += "��"HIC"(perform+)"NOR;
		for(i=0; i < j; i++){
			if (i % 4 == 0)
			{
				for (k = 52-templen; k >0; k--)
					str += " ";
				str += "��\n��          ";
				templen = 0;
			}
			str += sprintf("%s ",WHT+replace_string(skfile[i], ".c", "")+NOR);
			templen += strlen(replace_string(skfile[i], ".c", "")) +1;
		}
		for (k = 52-templen; k >0; k--)
			str += " ";
		str += "��\n";
	}
	str += "������������������������������������������������������������������\n";
	write(str);
	return 1;
}

string skill_enables(object sk)
{
	int i, j, k, templen;
	string str, *skills;
	skills = keys(valid_type);
	
	for(i=0; i < sizeof(skills); i++) {
		if (sk->valid_enable(skills[i])) continue;
		skills[i] = 0;
	}
	
	skills -= ({ 0 });
	j = sizeof(skills);
	if( !j || j < 1)
		return "";
	str = "��"HIY"���⼼��"NOR"��                                                    ��\n";
	str += "��"HIC"(enable+ )"NOR;
	templen = 0;
	for(i=0; i < j; i++) {
		if (i % 4 == 0)
		{
			for (k = 52-templen; k >0; k--)
				str += " ";
			str += "��\n��          ";
			templen = 0;
		}
		str += sprintf("%s ", valid_type[skills[i]]+"("+skills[i]+")");
		templen += strlen(valid_type[skills[i]]+"("+skills[i]+")") + 1;
	}
	for (k = 52-templen; k >0; k--)
	{
		str += " ";
	}
	str += "��\n";
	return str;
}
int sort_skill(string file)
{
	int i;
  if (strlen(file) < 2) return 0;
  if (file[strlen(file)-2..strlen(file)-1]!=".c") return 0;
//	if ( !sscanf(file, "%*s.c") ) return 0;
	i = strlen(file);
	while(i--){
		if( file[i] == '.' ) continue;
		if( (file[i] < 'a' || file[i] > 'z' )
		    && (file[i] < '0' || file[i] > '9' )
		)
			return 0;
	}
	return 1;
}

int help(object me)
{
	write(@HELP

ָ���ʽ��help <����>              ���磺> help cmds
          help <�书��>            ���磺> help force
          help <��������>()        ���磺> help call_out()
          help here                ��ʾ���ڵ���Ľ���

    ���ָ���ṩ�����ĳһ�������ϸ˵���ļ������ǲ�ָ�����⣬
���ṩ���й�������ļ���

HELP
	);
	return 1;
}

